# Automatic CAN Headers

An Ultra Portable "library" meant to contain the maps for the T24e can library

This will enable you to decode or encode messages, fetch id's and prevent bugs without any significant  effort.

## Installing

### Non Git projects:

1. Go to the folder where you want the files to be in(**reminder that it will still create another folder**)
2. Paste the command bellow:

```
git clone https://github.com/FSLART/Can-Header-Map
```

Note: **Windows might not have git configured to work in your command prompt** you can use any client(vscode, intellij, mplab, gitkraken, manual download,...) to clone

### Git Projects

1. Its as shrimple as going to the root folder(ie project)
2. paste the command bellow

```
git submodule add https://github.com/FSLART/Can-Header-Map <directory-you-want-your-file-to-be>
```

## How it works

TODO: call Perdu or Jão to explain this

## Contributing

If you're unaware on how to work with git ask jão.
Rules are Master is only used for stable/tested versions use Dev Branch to paste your finished work.

## Why the F*ck would i use this

Doing all the work of properly fetching data from a full array **isnt a prestigious job**, nor will anyone clap their hands because you successfully decoded a message acording to what was previously defined.

As such working with byte or worse, bitwise operations, is a dull and gruesome task which is prone to error and wastes time when you could be doing better jobs.

As such this library is designed to be easy to install, light, and easy to work with, hopefully this will increase the throughput of significant work.

**Pro Tip: Its better for 5 people to find and solve 20 shared bugs than it is for one person to find and solve a single bug.**

## This sucks! Why is the library so crappy?

See: Contributing

## It doesnt even work properly!!!

See: Contributing

## Headers
All headers for both can and canfd are prefixed with CAN(all in caps), and suffixed with db and its respective extension
CAN_asdb.h : Contains the header for the autonomous system bus 
CAN_datadb.h : Contains the header for the data bus
	