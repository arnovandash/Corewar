#First attempt at making a corewar champion.

.name "test"
.comment "This just tests things."

pre:
	st		r1, r2
	st		r3, -4
	st		r2, 6
	live	%0

init:
	ld		%4, r3
	ld		%2, r4
	ld		%:end, r5
	ld		%2, r6

split:
	fork	%:start
	ld		%0, r15
	zjmp	%:start

copy:
	ldi		%:pre, r3, r7
	sti		r7, r5, %50
	add		r4, r3, r3
	add		r6, r5, r5
	st		r2, 6
	live	%1
	ld		%0, r15
	zjmp	%:copy

start:
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	live	%0
	fork	%:init2
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	live	%0
	fork	%:master

copy_cat:
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	st		r2, 6
	live	%0
	fork	%:init
	st		r2, 6
	st		r2, 6
	live	%0
	fork	%:start
	st		r2, 6

master:
	st		r2, 6
	live	%0
	fork	%:start
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	live	%0
	fork	%:master
	st		r2, 6
	live	%0
	fork	%:init2

mad_live:
	st		r2, 6
	live	%0
	st		r2, 6
	live	%0
	st		r2, 6
	live	%0
	ld		%0, r15
	zjmp	%:mad_live

init2:
	ld		%4, r3
	ld		%2, r4
	ld		%120, r5
	ld		%2, r6

copy2:
	lldi	%:pre, r3, r7
	sti		r7, r5, %50
	add		r4, r3, r3
	add		r6, r5, r5
	st		r2, 6
	live	%1
	ld		%0, r15
	zjmp	%:copy

end:

