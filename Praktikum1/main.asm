.include "m328pdef.inc"	; Prozessordefinitionen laden

.equ GRUEN=1
.equ GELB=2
.equ ROT=4

.org 0x00		; Reset Vektor
 rjmp start

start:
	ldi r24, LOW( RAMEND )
	out SPL, r24
	ldi r24, HIGH( RAMEND )
	out SPH, r24

ldi r24, 0x7 ; Pin 10(rot),9(gelb) und 8(grün) am Arduino Uno als Ausgänge gestezt
OUT DDRB, r24		;DDR setzten

.def delay_0 = R17 ;Definiere Register R17 für delay_0
.def delay_1 = R18 ;Definiere Register R18 für delay_1
.def delay_2 = R19 ;Definiere Register R19 für delay_2


main:			   ;Anfang des Programms

rcall setdelay

ldi r24, ROT;setze Rote LED an
OUT PORTB, r24	   ;Übergebe R24 an den Ausgang

rcall delay		   ;Führe delay aus und komme hierhin zurück(PC+1)

rcall setdelay	   ;Setzte delaywerte

ldi r24, GELB	;Gelbe LED an
OUT PORTB, r24   ;Übergebe R24 an den Ausgang

rcall delay		   ;FÜhre delay aus und komme hierhin zurück(PC+1)

rcall setdelay	   ;Setzte delaywerte

ldi r24, GRUEN; Grüne LED an
OUT PORTB, r24	   ;Übergebe R24 an den Ausgang

rcall delay		   ;Führe delay aus und komme hierhin zurück(PC+1)

rcall setdelay	   ;Setzte delaywerte

ldi r24, GELB;Gelbe LED an
OUT PORTB, r24	   ;Übergebe R24 an den Ausgang

rcall delay		   ;Führe delay aus und komme hierhin zurück(PC+1)

rjmp main	       ;Springe zurück nach Loop


delay:			   ;Zeitverzögerung
	dec delay_2	   ;delay_2 wird um eins gesenkt
	brne delay	   ;delay_2 wird verglichen

	dec delay_1   ;delay_1 wird um eins gesenkt
	brne delay	   ;delay_1 wird verglichen

	dec delay_0   ;delay_0 wird um eins gesenkt
	brne delay	  ;delay_0 wird verglichen


	ret			  ;Gehe zur Rücksprungadresse


setdelay:

	ldi delay_0, 17	   ;Setzte Register R17(delay_0)
	ldi delay_1, 60   ;Setzte Register R18(delay_1)
	ldi delay_2, 204   ;Setzte Register R19(delay_2)




	ret				   ;Gehe zur Rücksprungadresse
