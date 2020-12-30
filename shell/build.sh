#! /bin/bash
# run from root of linux mainline after making changes
# dont forget to checkpatch.pl -f <file> !
# do git oneline to get formatting of patch subject

WORKDIR=`echo $(pwd)`/
CONFIG=`echo /boot/$(ls -1 /boot/ | grep config | tail -1)`
echo setting working directory to: $WORKDIR
sleep 5
echo grabbing latest changes
sleep 5
git checkout master && git stash && git pull
echo cleaning up relase candiates
sleep 5
cd /boot/ && sudo rm -f *rc* && cd /boot/loader/entries && rm -f *rc* && cd $WORKDIR
echo setting latest config to: $CONFIG
sleep 5
cp $CONFIG .config
make listnewconfig
lsmod > /tmp/my-lsmod
make LSMOD=/tmp/my-lsmod localmodconfig
echo compiling kernel
sleep 5
make -j4 all
# get all dmesg to compare after install
echo collecting dmesg
sleep 5
dmesg -t > dmesg_current
dmesg -t -k > dmesg_kernel
dmesg -t -l emerg > dmesg_current_emerg
dmesg -t -l alert > dmesg_current_alert
dmesg -t -l crit > dmesg_current_alert
dmesg -t -l err > dmesg_current_err
dmesg -t -l warn > dmesg_current_warn
echo installing kernel
sleep 5
sudo make modules_install install
echo booting into $(ls /boot/ | grep rc | tail -1)
echo press ctrl+c to abort
sleep 15
sudo reboot

# if all good git commit -m "message" <file>
# git format-patch -1 <commitId>
# mutt -H 000-mychange.patch

# On first compile there might issues 
# install openssl-devel, dwarves, elf-utils and try make prepare
