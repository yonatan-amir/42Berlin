#!/bin/bash
find . -name "*.sh" | sed 's/\.sh$//; s#.*/##'