The Relay i am using is Songle SRD-05VDC-SL-C, this relay has 3 pin:
1. Input Pin
2. Ground Pin
3. 3.3 Volt Pin

  
these pin are responsible 'switch' the current from Normaly Close (NC) gate to Normaly Open (NO) gate  

some of the gate in these relay:
1. 常开 (cháng kāi) → Normally Open (NO)
2. 公共端 (gōng gòng duān) → Common (COM)
3. 常闭 (cháng bì) → Normally Closed (NC)

to use the relay:  
put COMMON on 3.3V Pin  
NO and NC on positive leg of your Electric Component and then the negative leg to ground  
and then set initial state for the relay Input Pin,  
//    if Active Low then set your initial pin state to HIGH  
//    if Active High then set your initial pin state to LOW  
//       **Active State -> kapan gerbang NO akan ditutup  
