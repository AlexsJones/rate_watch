rate_watch
=========

A tool for contractors to calculate how much they've already earnt (For those days you just need a bit of inspiration)

See it in action: http://showterm.io/4dd30ac2904037e514392

Installation
============

- Install prebuilt binaries
```
	sudo ./install_binary.sh
```

- Build it yourself

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
