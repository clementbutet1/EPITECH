#!/bin/bash
grep -E 'theo1|steven1|arnaud1|pierre-jean' | sed -e 's/steven1/Daffy Duck/' -e 's/theo1/Wile E. Coyote/' -e 's/arnaud1/Porky Pig/' -e 's/pierre-jean/Marvin the Martian/'