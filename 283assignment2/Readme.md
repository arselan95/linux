<h1>
Modifying Instruction Behavior in KVM</h1><br>
<h2>Question 1 :About Team </h2><br>
 <h4>Arselan (me)</h4><br>
 <ul>
 <li>Used VMWare fusion as a Virtual Machine </li><br>
 <li>Researched and built/compiled Linux Kernel source code and got the environment setup. </li><br>
  <li>Researched about external Kernel packages required to modify and load the kvm modules in Kernel </li><br>
 <li>Implemented vmx.c and cpuid.c as per the assignment requirements.</li> <br>
 <li>Tested it by creating a test.c file and and also by loading the new module and verified the output.</li></ul><br> 
<h4>Rajakumari</h4><br>
<ul>
<li>Researched about the KVM files and which files are required to edit. </li><br>
<li>Researched about CPUID emulation code to figure out the number of exits and time spent in the exits. </li><br>
 <li>Worked on the cpuid.c and vmx.c file implementation. </li><br>
</ul><br>
 
<h2>Question 2 : Implementation of the software</h2><br>

<h4>Build Linux Kernel Source code</h4><br>
<ul>
<li>Download Linux Kernel Archive from kernel.org. </li><br>
<li>Download the tarball file (5.9 used for this assignment)</li><br>
<li>Run command ‘sudo apt install build-essential rsync gcc bc bison libssl-dev libncurses5-dev libelf-dev’</li><br>
<li>Run command ‘sudo update-grub’</li></ul><br>

<h4>Get the Linux Kernel tarball file and untar it</h4><br>
<ul>
<li>Run command ‘wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.tar.xz’</li></ul><br>

 <h4>Configure the Kernel Compilation and Compile the Kernel</h4><br>
 <ul>
<li>Copy the config file that came with the linux distribution. </li><br>
<li>Run command ‘make deb-pkg’</li><br>
 <li>Make sure Kernel has compiled successfully. Reboot</li></ul><br>
 
![Screenshot](5.png)

<br>
<h4>Modify the KVM behavior</h4> <br>
<ul>
<li>Modify the files in linux/arch/x86/kvm/cpuid.c and linux/arch/x86/kvm/vmx/vmx.c files </li><br>
<li>In vmx.c create an exit_counter and exit_delta_tsc. </li><br>
<li>Edit vmx_handle_exit() by getting the time difference to calculate time taken for exit cycles and increment the exit counter to get the count of exits. </li><br>
<li>In cpuid.c fetch exit_counter and exit_delta_tsc, imported from vmx.c </li><br>
<li>Make changes in the kvm_emulate_cpuid() method by passing the exit_counter and exit_delta_tsc in the eax, ebx and ecx registers. </li><br>
<li>Build the kvm and kvm-intel modules to test the new changes</li><br>
<li>Run command 'sudo make modules SUBDIRS=arch/x86/kvm/'</li><br>

![Screenshot](makemodules1.png)
![Screenshot](makemodules2.png)

<li>Run command ‘sudo rmmod kvm’</li><br>
<li>Run command 'sudo rmmod kvm-intel'. </li><br>
<li>Reboot and Run command 'sudo insmod kvm-intel' and 'sudo insmod kvm'. </li><br>
<li>Make sure KVM is correctly loaded. </li><br>

![Screenshot](kvminfo.png)


<li></li> <br>
<li>Create a testassignment2.c file to test the exits and cycles in exit.</li></ul><br>
<li>Compile and Run. </li><br>

![Screenshot](finaloutput.png)

 <h5><i>Note: Make sure you have enabled "pass through virtualization extensions" in your VM !</i></h5><br>
 
 <h4>Question 3: About frequency of exits</h4><br>
<ul>
<li>They do not increase at a stable rate. </li>
<li>More exits performed when I try to run other instructions such as I/O. </li>
 <li>Full VM boot entails approximately 22 exits. </li>
</ul><br>
