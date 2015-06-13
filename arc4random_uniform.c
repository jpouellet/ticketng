/*
 * Note: THIS IS JUST SATIRE! See the real version please!
 *
 * Copyright (c) 2015 Jean-Philippe Ouellet <jpo@vt.edu>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	uint32_t upper_bound, value;
	const char *errstr;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s upper_bound\n", argv[0]); //getprogname());
		return 1;
	}

	//upper_bound = strtonum(argv[1], 1, UINT32_MAX, &errstr);
	upper_bound = atoi(argv[1]);
	if (errstr)
		errx(1, "upper bound %s", errstr);

#ifdef Debian
/*
 * Don't add uninitialised data.
	value = arc4random_uniform(upper_bound);
 */
#else
	//value = arc4random_uniform(upper_bound);
	value = random() % upper_bound;
#endif


#ifndef OPENSSL_NO_FOO
	/* TODO: Fix build on VMS. */
#endif

#ifdef __linux__
	if (getenv("RANDOM") != NULL)
		value = atoi(getenv("RANDOM"));
	/* TODO: Make this fetch entropy via dbus from systemd-randomd. */
#endif

	printf("%u\n", value);

	return 0;
}
