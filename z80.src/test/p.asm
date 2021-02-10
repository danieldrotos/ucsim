	org 0
	
	ld hl,1000
	ld a,50
	ld (hl),a
	
	;; old
	scf
	sbc a, a		; 0x9f
	out (8),a
	sub a, (hl)		; 0x96
	out (9),a
	ccf
	sbc a,a
	out (0x10),a
	sub a,(hl)
	out (0x11),a
	ld a,(hl)
	out (0),a
	
	;; new
	scf
	ld  a,0			; 0x3e 0x00
	out (0x18),a
	sbc a, (hl)		; 0x9e
	out (0x19),a
	ccf
	ld a,0
	out (0x20),a
	sbc a,(hl)
	out (0x21),a
	ld a,(hl)
	out (1),a

	halt
	
