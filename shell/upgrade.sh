#! /bin/bash
echo refreshing...
sleep 5
# sudo dnf upgrade --refresh -y
sleep 5
echo downloading upgrade to fedora $1
sleep 5
# sudo dnf system-upgrade download -y --refresh --releasever=$1
sleep 5
echo rebooting....
sleep 5
# sudo dnf system-upgrade reboot

# comment out sudo steps when not in use
# if not working probably you forgot to sudo dnf install dnf-plugin-system-upgrade