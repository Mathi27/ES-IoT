Slot Machine type game using Arduino.
There are 3 lights connected to the board.
Each light displays 6 colors. (R G B C M Y)
It cycles through these colors and each led has a random color assigned to it.
Random is done with a seed and analogWrite.
The green pushbutton is used to start the "Roll".
The player Starts with 2000 points.
If no LEDs have a common color, then it is a 'BUST' and the player loses 500 points.
If two LEDs have the same color then the play is 'SAFE' and gains 500 points.
If all the LEDs have the same color it is a 'JACKPOT' and the player gains 2500 points.
(6/216 chance of JACKPOT) (90/216 chance of SAFE) (120/216 chance of BUST).
(6/216 X 2500) + (90/216 X 500) + (120/216 X -500) = 0;
Each roll is fair and the average profit by the player in a total game should tend towards 0.
The House does not make profit from the points being in favour of the House.
A player can chose to CASHOUT the points anytime they wish.
The second red pushbutton is used to cashout.
This cashout has a 10% fee. This reduces 10% of whatever the players ending balance is.
This means that since the roll is fair and net profit should be equal to zero on average.
Since the players start with 2000 points 10% of that is 200 points.
The House makes 200 points on average per player.
Slot Machine.
