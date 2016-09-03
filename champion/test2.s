#First attempt at making a corewar champion.

.name "test"
.comment "This just tests things."

pre:
	st		r1, 6
	live	%0
	fork	%:pre

start:
	ld		%0, r2
	ld		%1, r3
	ld		%200, r4
	ld		%4, r8

init:
	st		r1, 6
	live	%0

function:
	ldi		%:function, r2, r6
	sti		r6, r4, %50
	add		r3, r2, r2
	add		r8, r4, r4
	st		r1, 6
	live	%0
	ld		%0, r7
	zjmp	%:function

end:
