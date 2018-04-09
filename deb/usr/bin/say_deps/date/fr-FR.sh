#!/bin/bash

hour="`date +"%_H"`";
min="`date +"%M"`";

if [ $min -eq "00" ]; then
	if [ $hour -eq "0" ]; then
		say "Il est minuit"
	elif [ $hour -eq "1" ]; then
		say "Il est une heure"
	else
		say "Il est $hour heures"
	fi
else
	if [ $hour -eq "0" ]; then
		say "Il est minuit $min"
	elif [ $hour -eq "1" ]; then
		say "Il est une heure $min"
	else
		say "Il est $hour heures $min"
	fi
fi
