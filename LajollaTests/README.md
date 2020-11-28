# Tests with a one-channel Lajolla riometer

Basically the task is to read the voltage output from the device and then log the results with a timestamp into a file. The very first prototype uses an Arduino and a pretty standard Linux computer.

## Old file format

To be compatible with the software used by the other UiT riometers, the fileformat to be used is as follows:
```
.
.
.
1605484804 40462 0
1605484806 40598 0
1605484808 40590 0
1605484810 40658 0
1605484812 40606 0
1605484814 40762 0
1605484816 40473 0
1605484818 40618 0
1605484820 40464 0
1605484822 40481 0
1605484824 40587 0
.
.
.
```
where the first number is the epoch time in seconds (i.e. unix timestamp) and the second number is the output value. The third number is not currently used and its value is usually zero.
