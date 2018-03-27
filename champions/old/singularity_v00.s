#First attempt at making a corewar champion.

.name "singularity v0.0"
.comment "The more it consumes, the more it is able to consume."

start:
	st		r1, 6
	live	%21
	fork	%:vsetup
	zjmp	%:start

vsetup:
	st		r1, %:vlive
	st		r1, %:vsetup2

vlive:
	live	%123
	add		80, %:vcatch

vcatch:
	st:		

vsetup2:
	st		%0, r1
	zjmp	%:vlive
