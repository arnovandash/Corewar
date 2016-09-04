#First attempt at making a corewar champion.

.name "hi-jacker v0.1"
.comment "Rogue processes hi-jack the opponents live command."

start:
	st		r1, 6
	live	%0
	fork	%:v1
	zjmp	%:start

v1:
	st		r1, 6
	live	%1
	fork	%:v2
	zjmp	%:start

v2:
	st		r1, 6
	live	%1
#	ld		%:start, r1
	zjmp	%:v2

v3:
	st		r1, 6
	live	%1
	zjmp	%:v3
