<h1>Assignment 1<br>
CMPE 283<br><br>
Discovering VMX Features</h1><br>

<h2>Question 1 </h2><br>
 <h4>Arselan (me)</h4><br>
 <ul>
 <li>Used VMWare fusion as a Virtual Machine </li><br>
 <li>Researched and built/compiled Linux Kernel source code and got the environment setup. </li><br>
 <li>Implemented 283-1.c file.</li> <br>
 <li>Tested it by loading the new module and verified the output.</li></ul><br>
  
<h4>Rajakumari</h4><br>
<ul>
<li>Researched about VMX virtualization features and MSRs. </li><br>
<li>Researched Intel 64 and IA-32 Architectures Software Developer’s Manual Vol:3C about various VMX configuration MSRs to the capabilities and features as listed in<br> the assignment which were used in the 283-1.c file implementation. </li><br>
 <li>Worked on the 283-1.c file implementation. </li></ul><br>
 
<h2>Question 2 : Implementation of the software</h2><br>
<h4>Configure a Linux Machine.</h4> <br>
<ul>
<li>Download VMWare Fusion or any VM of your choice. (or use parallels)</li> <br>
<li>Download Ubuntu 20.04<br>
<li>Create a new VM in VMWare Fusion by dragging the .iso file which will install Ubuntu OS in the VM.</li><br>
<li>Specs used: </li><br>
<li>CPU processor cores: 2</li><br>
<li>Memory: 4 GB</li><br>
<li>Disk: 105 GB</li></ul><br>
<h4>Build Linux Kernel Source code</h4><br>
<ul>
<li>Download Linux Kernel Archive from kernel.org. </li><br>
<li>Download the tarball file (5.9 used for this assignment)</li><br>
<li>Install following packages:</li><br>
<li>Run command ‘sudo apt install build-essential rsync gcc bc bison libssl-dev libncurses5-dev libelf-dev’<br>
<li>Update grub file </li><br>
<li>Run command ‘sudo update-grub’</li></ul><br>
<h4>Get the Linux Kernel tarball file and untar it</h4><br>
<ul>
<li>Run command ‘wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.tar.xz’</li><br>
<li>Create a new directory ‘LinuxKernel’ and untar the file</li><br>
<li>Run command ‘mkdir yourdirname’</li><br>
<li>Run command ‘tar xvf linux-* -C yourdirname/ --strip-components=1’</li></ul><br>
 <h4>Configure the Kernel Compilation and Compile the Kernel</h4><br>
 <ul>
<li>Copy the config file that came with the linux distribution. </li><br>
<li>Run command ‘cp /boot/config-$(uname -r) ./.config’</li><br>
<li>Compile kernel by running this command in your directory.</li><br>
<li>Run command ‘make deb-pkg’</li><br>
 <li>Kernel will compile. This process took 5.5 hrs for me.</li> <br>
 <li>Make sure Kernel has compiled successfully. </li></ul><br>
![Screenshot](5.png)<br>

<h4>Create a new Linux Kernel module that will query various MSR’s to determine Virtualization features.</h4> <br>
<ul>
<li>Inside your LinuxKernel directory create a new directory</li><br>
<li>Run command ‘mkdir 283assignment1’</li><br>
<li>Go to the 283assignment1 directory and create a cmpe283-1.c file</li><br>
<li>Run command ‘mkdir cmpe283-1.c’</li><br>
<li>Add the required functionality. </li><br>
<li>Download the file ‘cmpe283-1.c’ and ‘makefile’ from the github link provided and run command ‘make’ while you are in the 283assignment1 directory.</li> <br>
<li>This will create ‘cmpe283-1.ko’ which we will use to load new modules into Kernel.</li></ul><br>
![Screenshot](6.png)<br>
 <h4>Load the new module in the Kernel</h4><br>
 <ul>
<li>Run command ‘sudo insmod ./cmpe283-1.ko’</li><br>
<li>It will call init_module() which will call detect_vmx_features();</li><br>
<li>To stop use command ‘sudo rmmod ./cmpe283-1.ko’</li><br>
<li>Call cleanup_module()</li></ul><br>
Run command ‘dmesg’ to see syslog. <br>

Output of the module<br>
![Screenshot](1.png)
![Screenshot](2.png)
![Screenshot](3.png)
![Screenshot](4.png)
