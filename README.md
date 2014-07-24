rate_watch
=========

A tool for contractors to calculate how much they've already earnt (For those days you just need a bit of inspiration)

See it in action: http://showterm.io/4dd30ac2904037e514392

Installation
============

Either build it or just install the prebuild binary

####Install prebuilt binary [currently built for  Mach-O 64-bit executable x86_64] 
```
	sudo ./install_binary.sh
```

####Build it yourself

Requires : cmake, os-x/linux,gcc
```
cmake .
make
sudo make install
```

Usage
====

```
#$>rate_watch -h [START_HOUR] -m [START_MINUTE] -r [DAILY RATE] -d [DAY LENGTH]
$>rate_watch -h 9 -m 0 -r 100 -d 8
```

Example output:
Updates once a second
```
$> You've earnt £50.0151 
```

Known issues & future improvements
==================================

Unless you are extremely lucky; lunch breaks are not usually paid for.
This actually doesnt effect the overall average but it would be better if the ticket stopped at lunch time - Just to remind yourself to go enjoy that hour of unpaid respite.
