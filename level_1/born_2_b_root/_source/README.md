_This project has been created as part of the 42 curriculum by yamir._

# Born2beRoot

## Description

Born2beRoot is a system administration project focused on installing and securing a minimal Rocky Linux server inside a virtual machine. The goal is to practice virtualization, storage planning with encrypted LVM, service hardening (SSH, firewall, sudo), and automated system monitoring.

## Instructions

### VM setup

- Create a VirtualBox VM and install the latest stable Rocky Linux (server, no GUI).
- Use encrypted LVM with at least two logical volumes (e.g., `/` and `/home`).
- Set the hostname to `yamir42`.

### Access

- SSH runs on port `4242`.
- Root login over SSH is disabled.
- Firewall allows only port `4242`.

### Monitoring

- `/usr/local/bin/monitoring.sh` broadcasts system stats via `wall`.
- It runs at startup and every 10 minutes via root’s crontab.

## Resources

- Rocky Linux documentation
- man pages: `sshd_config`, `sudoers`, `firewalld`, `cron`, `wall`, `lvm`
- 42 Born2beRoot subject PDF

**AI usage**

- Used to clarify requirements and explain configuration steps.
- Used for reasoning about command choices and debugging.
- All configuration was applied manually and verified on the VM.
- Used to polish wording and improve clarity in this README.

## Project description (OS choice and design)

### OS choice: Rocky Linux

**Pros**

- RHEL-compatible, commonly used in enterprise environments.
- SELinux and firewalld provide strong, granular security controls.

**Cons**

- More complex for beginners than Debian.
- SELinux policies and firewall zones require extra configuration.

### Design choices

- **Partitioning**: Encrypted LVM for `/` and `/home`, unencrypted `/boot`.
- **Security**: SELinux enforcing, SSH on port 4242, root SSH disabled.
- **Users**: root plus user `yamir`, added to `user42` and `sudo`.
- **Services**: Minimal server install, no graphical interface.

## Comparisons

### Debian vs Rocky Linux

- **Debian**: simpler tooling, AppArmor, UFW, beginner-friendly.
- **Rocky**: enterprise-aligned, SELinux, firewalld, RHEL compatibility.

### AppArmor vs SELinux

- **AppArmor**: profile-based, simpler to configure.
- **SELinux**: label-based, more granular and powerful but complex.

### UFW vs firewalld

- **UFW**: straightforward interface, common on Debian/Ubuntu.
- **firewalld**: dynamic zones and runtime changes, standard on RHEL/Rocky.

### VirtualBox vs UTM

- **VirtualBox**: common on x86_64, good cross-platform support.
- **UTM**: preferred on Apple Silicon, based on QEMU.
