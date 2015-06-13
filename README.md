Apparently it's BSDCan tradition to have an OpenBSD person run the
ticket-selection script for the raffle during the closing ceremony...
[perhaps for good reason][rng]. Since Henning didn't come this year, I was
asked to do it. I'm not an OpenBSD committer or anything, but apparently I'm
considered associated enough with the project to be the honorary
button-pressing monkey.
[rng]: https://lists.freebsd.org/pipermail/freebsd-current/2015-February/054580.html "URGENT: RNG broken for last 4 months"

So... if I was going to do this, I was going to do it right. I asked for the
random number picking script so I could audit it because it'd be silly to
assert that merely by my running some arbitrary script it somehow becomes a
fair process.

Turns out, that script had a silent limitation of never letting anybody with
a ticket number above 256 win. Perhaps there was an implicit assumption that
the FreeBSD foundation wouldn't ever have that many donors or something? Idk.

So, I rewrote it the way I'd imagine a real OpenBSD person would.

$ man arc4random_uniform
```
ARC4RANDOM_UNIFORM(1)	    General Commands Manual	 ARC4RANDOM_UNIFORM(1)

NAME
     arc4random_uniform - trivial wrapper around the libc routine

SYNOPSIS
     arc4random_uniform upper_bound

DESCRIPTION
     The arc4random_uniform utility prints a single number uniformly
     distributed but less than upper_bound.

     upper_bound must be between 1 and UINT32_MAX inclusive.

EXIT STATUS
     The arc4random_uniform utility exits 0 on success, and >0 if an error
     occurs.

EXAMPLES
     To emulate the default behavior of the old BSDCan script:

	   $ arc4random_uniform 51

HISTORY
     arc4random_uniform was written after looking at Ed Maste's shell script
     from BSDCan 2015 and seeing that it had a silent limit never allowing
     anybody with a ticket number above 256 to win the raffle.

AUTHORS
     The arc4random_uniform utility was written by Jean-Philippe Ouellet
     <jpo@vt.edu>.

CAVEATS
     This program is not suitable for raffles at conferences of more than
     UINT32_MAX people.

OpenBSD 5.7			 June 13, 2015			   OpenBSD 5.7
```
