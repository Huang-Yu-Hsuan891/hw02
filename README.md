# hw02
# step1 Add buttons on the bread board (as DigitalIn): up, down and select.
# so I set pin D3 is up bottom, pin D4 is down bottom, and pin D5 is select, up and down to choose frequency 
# step2  display on uLCD to select from a few frequencies by your choice ( I have two choice 2HZ and 5HZ, my cut off frequency is about 4HZ ), and my uLCD print now frequency you choose.
#  step3 Generate waveform, my ID is 108061136, so S = 10; first I cut 1s/frequency to 128， then AnalogOut  aout = i * frequency; then this sisgnal will put into low-pass filter, and i will get AnalogIn Ain signal, I store this in ADCdata, and then print this ADCdata, by FFT.py to get the picture.
# the result is when frequency bigger then cut off frequency than signal pass low pass filter the output amplitude is lower than input .

