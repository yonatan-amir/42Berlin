_This project has been created as part of the 42 curriculum by yamir._

# Born2beRoot

## Description

Born2beRoot is a system administration project where I installed and hardened a
minimal Rocky Linux server in VirtualBox.

Mandatory target:

- no GUI
- encrypted LVM-based storage
- SSH on port `4242` with root SSH login disabled
- active firewall with only `4242` open
- strong password and sudo policy
- automatic monitoring broadcast every 10 minutes and on boot

## Instructions

### Project files to submit

- `README.md`
- `signature.txt`

Not the VM itself.

### Step-by-step setup (the way I configured it)

1. Create VM in VirtualBox and install Rocky Linux (minimal/server install, no GUI).
2. During disk setup:
   - create separate `/boot` (unencrypted)
   - use LVM for system volumes
   - enable encryption for LVM logical volumes
3. Set hostname:

```sh
sudo hostnamectl set-hostname yamir42
```

4. Create required groups and user assignment:

```sh
sudo groupadd -f user42
sudo groupadd -f sudo
sudo usermod -aG user42,sudo yamir
```

5. SSH hardening (`4242`, no root login) with manual file edits:

```sh
sudo nano /etc/ssh/sshd_config
# set:
# Port 4242
sudo nano /etc/ssh/sshd_config.d/99-b2br.conf
# set:
# PermitRootLogin no
# PasswordAuthentication yes
sudo systemctl restart sshd
sudo sshd -T | grep -E '^(port|permitrootlogin|passwordauthentication) '
```

6. Firewall (`firewalld`) with only SSH custom port:

```sh
sudo systemctl enable --now firewalld
sudo firewall-cmd --permanent --remove-service=ssh
sudo firewall-cmd --permanent --add-port=4242/tcp
sudo firewall-cmd --reload
```

7. Keep SELinux enforcing at boot:

```sh
sudo nano /etc/selinux/config
# set:
# SELINUX=enforcing
```

8. Password age policy (`/etc/login.defs`):

```sh
sudo nano /etc/login.defs
# set:
# PASS_MAX_DAYS 30
# PASS_MIN_DAYS 2
# PASS_WARN_AGE 7
sudo chage -M 30 -m 2 -W 7 yamir
sudo chage -M 30 -m 2 -W 7 root
```

9. Password complexity policy (`/etc/security/pwquality.conf`):

```sh
sudo nano /etc/security/pwquality.conf
# set:
# difok = 7
# minlen = 10
# dcredit = -1
# ucredit = -1
# lcredit = -1
# maxrepeat = 3
```

10. Sudo hardening (`visudo` recommended):

```sh
sudo visudo
```

Add/ensure these lines:

```text
Defaults    passwd_tries=3
Defaults    badpass_message="Wrong Password. YOU SHALL NOT PASS!!"
Defaults    log_input
Defaults    log_output
Defaults    use_pty
Defaults    iolog_dir="/var/log/sudo"
Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
```

11. Monitoring script:

Create `/usr/local/bin/monitoring.sh`, then:

```sh
sudo chmod +x /usr/local/bin/monitoring.sh
sudo crontab -e
# this edits root's crontab (stored by system under /var/spool/cron/root)
```

Root crontab entries:

```text
*/10 * * * * /usr/local/bin/monitoring.sh
@reboot /usr/local/bin/monitoring.sh
```

12. Generate virtual disk signature:

```sh
# Run on host machine, from the VM disk directory:
sha1sum <vm_disk>.vdi
```

Put only the SHA1 hash in `signature.txt`.

## Final state on my VM

- OS: Rocky Linux `10.1` on VirtualBox
- Hostname: `yamir42`
- Disk: `/boot` + encrypted LVM (`/`, `/home`, swap)
- SSH: port `4242`, root SSH login disabled
- Firewall: only `4242/tcp`
- SELinux: enforcing
- user `yamir` in groups: `user42`, `sudo` (and `wheel`)
- monitoring script running on boot and every 10 minutes

## Project description (OS choice and design)

### OS choice: Rocky Linux

I chose Rocky because I wanted the challenge. At the beginning of this
project, many people told me Rocky was harder, so I wanted to try it myself.

I cannot make a full real-life Debian comparison from personal use, because this
is my first Linux server setup project.

### Design choices

- partitioning: encrypted LVM for `/` and `/home`, separate `/boot`
- security: SSH on `4242`, root SSH login disabled, SELinux enforcing
- user model: dedicated student user in `user42` and `sudo`
- minimal services only, no graphical stack

## Comparisons

### Debian vs Rocky Linux

- Debian is often recommended for beginners.
- Rocky felt more strict to me and harder at first.
- I chose Rocky for the challenge.

### AppArmor vs SELinux

- Both are Linux security systems.
- I only used SELinux in this project because Rocky uses it.
- My practical understanding: SELinux must stay `Enforcing` for this project.

### UFW vs firewalld

- Both are firewall tools.
- I used firewalld because Rocky uses it by default.
- I only configured what was required: open `4242/tcp`.

### VirtualBox vs UTM

- I used VirtualBox because I already knew it a bit.
- UTM is another VM tool, mainly used by some Mac users.
- I do not have hands-on UTM experience.

## My experience and learning

The hardest part for me was understanding command flow and output format in the
terminal. It was difficult at first to collect values from different commands and
format them exactly for `monitoring.sh`.

I made progress by re-reading each command slowly, testing one thing at a time,
and learning where configuration files are located in `/etc`.

The monitoring + cron part was the most difficult section for me:

- finding the correct commands for each required value
- understanding the output well enough to parse it
- formatting the final message exactly as expected

## Resources

- Rocky Linux docs: https://docs.rockylinux.org/
- `man sshd_config`
- `man sudoers`
- `man firewalld`
- `man pwquality.conf`
- `man chage`
- `man cron`, `man crontab`, `man wall`
- 42 Born2beRoot subject PDF

AI usage:

- used to help structure this README and checklist
