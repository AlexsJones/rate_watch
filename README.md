rate_watch
=========

![alt text](http://i.imgur.com/QGtbsO6.png?1 "example")


A tool for contractors to calculate how much they've already earnt (For those days you just need a bit of inspiration)

See it in action: http://showterm.io/efe03a63d52d50d8c1d24

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

Working over your hours: 

In the emergency where you forget you've worked over your hours
```
You've earnt £2520.833740 [ALERT - WORKING TOO HARD (Possibly not getting paid)]
```

Known issues & future improvements
==================================

Unless you are extremely lucky; lunch breaks are not usually paid for.
This actually doesnt effect the overall average but it would be better if the ticket stopped at lunch time - Just to remind yourself to go enjoy that hour of unpaid respite.
