# say!

Say is a text to speech program for Debian based systems. This tool allows you to read texts from many sources orally. Read text can be output to an audio file saved on your system.

## Flexible

The **say** command accepts all types of call that can be made within a terminal.

Text can be given to **say** through its arguments or standard input. **-f** options also allows you tu define a file to be read. The **xsel** option causes to read the text selected with your mouse within your graphical interface.

The program comprehends over to 6 languages with a human feeling:

- English (US)
- English (GB)
- French
- Deutsch
- Italian
- Spanish

Speech loudness and rate can also be specified thanks command options. In same way, speech can be output to a given file path.

## Easy to use

Say comes with a keyboard shortcut configured to help you to read selected text more easilly. Simply select a text with your mouse, press \<Super\>+Escape ans **say** will read it!

A configuration panel is added to your **system preferences** section so you can define the default language, volume and speed that **say** will use by default.

## Give it a try!

### First of all

If you never used a *Makefile* before, there is a chance that you don't have the required package to process it. To solve this problem, simply open a terminal and type:

`sudo apt-get install build-essential`

### Install the program

Through a terminal, go to the say folder and type:

`make install`

This command will create a debian package and install it in your system.

**You're ready to go!**

## Usage Examples

### Most basic usage may be:

`say Hello World!`

All command arguments will be interpreted a being part of the text to read unless you specify command options.

### Basic command options

Basic command options permits you to customize the current command call. There are a few basic options:

- -f, --file
- -h, --help
- -l, --language
- -s, --speed
- -v, --volume

These options cann be added individually or combined. **-v** and **-s** options values go from 0.5 to 1.5. **-l** option accepts languages defined by their short or long name

Short Name | Long Name | Stands For
------------|------------|------------
en | en-US | English (US)
-- | en-GB | English (GB)
fr | fr-FR | French
de | de-DE | Deutsch
it | it-IT | Italian
es | es-ES | Spanish

#### Sample command calls

Try :

`say -v 0.5 Hey you, stop shouting!`

or

`say -s 1.5 What did you say?`

or even

`say -v 1 -s 0.8 Could you repeat please?`

Example with --file:

`say -l es -v 1.2 -s 0.7 -f path/to/file`

This command will get specified file's content and read it.

#### --config option

**-c, --config** option helps to modify the default configuration. It is used with **-l**, **-s** and **-v** options.

Simgle config option definition:

`say --config -l fr`

Multiple options can be defined at same time:

`say -s 1.5 -v 1.2`

**-d** option is a special one. When called with **--config** it resets system defaults configuration.

`say --config -d`

#### --xsel option

**-x, --xsel** option takes advantage of the xsel package. It allows **say** to read text from your GUI. You can combine this option with other basic options **-l**, **-s** and **-v**. This option is used by a keyboard shortcut installed with Say! that allows you to read texts within your GUI by selecting a text and pressing the shortcut (<Super>+Escape) to start reading.

Typing

`xsel | say`

is same as

`say --xsel`

You can combine it with basic options this way:

`say --xsel -l en-GB -v 1.3 -s 0.098`

#### --output

**-o, --output** option allows you to save the read text as an audio file. Currently, only *.wav* format is supported. This option can be combined to any say call except **--config**

Simple example

`say --output path/to/file.wav Hello World!`

Example with custom configuration

`say -l en-US -v 1.5 --output path/to/file.wav This audio file has a loud US English voice`

## RTFM

More details about **say** command usage can be found in the say's man pages.

## Troubleshooting

Say may use some non open free software.
