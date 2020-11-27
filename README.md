# Imaging riometer installation in Longyearbyen, Svalbard

## Background

In the 1990's, Peter Stauning from the Danish Meteorological Institute (DMI), Denmark, and Hisao Yamagishi from the National Institute for Polar Research (NIPR), Japan worked together with the University Centre in Svalbard (UNIS) and University of Tromsø (UiT). They installed an imaging riometer in Adventdalen near the town of Longyearbyen in Svalbard, Norway. In 2020, the ownership was transferred to UiT who desire to continue riometer observations in the high arctic.

The antenna old system comprises 64 dipole antennas which is still in working condition just like its associated RF electronics. However, the old PC with floppy disks, a large hard disk (200MB) and tape drives stopped recording data. The exact reason is not clear, but rather than rebuilding everything, it may well be a better idea to just build a new interface that can be used with modern computers.

This repository collects relevant information from the hardware/software engineering point of view.

We gratefully acknowledge the help of Peter Stauning, who retired from the DMI a long time ago yet is still active in the research world.

## Getting the data from the antenna field to the computer

The antennas are located about 650m from the old Nordlysstasjon in Adventdalen. In the middle of the antenna array, there is a small enclosure with RF and interface electronics. A 5-conductor main cable provides power from the station as well as carries the measured signals to the PC. The riometer essentially produces an 8x8 "picture" and the data is transferred to via a single conductor using phase encoding.

See the [wiki](https://github.com/mikkosyrjasuo/IRIS-riometer-Svalbard/wiki) for details.
