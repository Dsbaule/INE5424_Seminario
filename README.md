# INE5424 - Seminars

Prepare and present a seminar about one of the topics related to multicore scheduling on ARM processors. Seminars consist of a report and a set of slides in PDF format, and a tarball containing the source code used to validate the seminar along with a readme file containing detailed instructions on how to reproduce them. Files must be submitted through moodle until May 6th, 2019.

Group F: ARM AMBA

### Prerequisites

CodeSourcery toolchain: Available [here](http://www.dropwizard.io/1.0.2/docs/)

QEMU - On Debian Systems can be installed using: `$ sudo apt-get install qemu`. On Ubuntu, the package `qemu-kvm-extras` is also needed, use `$ sudo apt-get install qemu-kvm-extras` to install it.

### Running

Each ARM AMBA protocol has its own separate test.

From project root, run:

```
$ bash run.sh (APT | ATB | AHB)

```

### Expected Results

You should end up with Qemu running the tests, printing the results and running indefinitely. As bellow:
```
$ bash run.sh APB
pulseaudio: set_sink_input_volume() failed
pulseaudio: Reason: Invalid argument
pulseaudio: set_sink_input_mute() failed
pulseaudio: Reason: Invalid argument

Data: 0000179200 sent to address 0
Data: 0001653760 sent to address 1
Data: 0003128320 sent to address 2

Data: 0000179200 received from address 0
Data: 0001653760 received from address 1
Data: 0003128320 received from address 2
|
```
To exit, press `Ctrl + A` and then `X`
