#First attempt at making a corewar champion.

.name "singularity v0.1"
.comment "The more it consumes, the more it is able to consume."

pre:
	st		r1, r9
	st		r9, 6
	live	%0
	fork	%:master

start:
	st		r9, 6
	live	%0	

	ld		%0, r2
	ld		%1, r3
	ld		%70, r4
	ld		%4, r8

init:
	st		r9, 6
	live	%0

function:
	ldi		%:init, r2, r6
	sti		r6, r4, %50
	add		r3, r2, r2
	add		r8, r4, r4
	st		r9, 6
	live	%0
	ld		%0, r7
	zjmp	%:function

master:
	st		r9, 6
	live	%0
	fork	%:master
	st		r9, 6
	live	%0
	fork	%:master

slave:
	sti		r9, %:l1, %1
	sti		r9, %:l2, %1
	sti		r9, %:l3, %1
	sti		r9, %:l4, %1
	sti		r9, %:l5, %1
	sti		r9, %:l6, %1

l1:	live	%1
l2:	live	%1
l3:	live	%1
l4:	live	%1
l5:	live	%1
l6:	live	%1
	ld		%0	r7
	zjmp	%:l1

end:
	st		r9, 6
	live	%0
