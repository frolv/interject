/* 
 * 'interject': interject for a moment
 * Copyright (C) 2016 Alexei Frolov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

/* the name of the program */
static char *PROG_NAME = "interject";

/* all modifiable components */
static char *linux = "Linux";
static char *gnu = "GNU";
static char *operating = "operating system";
static char *useful = "GNU corelibs, shell utilities and vital system components";
static char *os = "OS";
static char *defined = "POSIX";
static char *developed = "GNU Project";
static char *kernel = "kernel";
static char *description = "the program in the system that allocates the "
		"machine's resources to the other programs that you run";

static int head = 0;

void interject();
int isvowel(char c);
void usage(char *s, FILE *f);

int main(int argc, char **argv)
{
	int c;
	static struct option long_opts[] = {
		{ "description", required_argument, 0, 'c' },
		{ "defined", required_argument, 0, 'd' },
		{ "developed", required_argument, 0, 'e' },
		{ "gnu", required_argument, 0, 'g' },
		{ "head", no_argument, 0, 'h' },
		{ "help", no_argument, 0, 'H' },
		{ "kernel", required_argument, 0, 'k' },
		{ "operating", required_argument, 0, 'o' },
		{ "os", required_argument, 0, 'p' },
		{ "useful", required_argument, 0, 'u' },
		{ "version", no_argument, 0, 'v' },
		{ 0, 0, 0, 0 }
	};
	while ((c = getopt_long(argc, argv, "hvH", long_opts, NULL)) != EOF) {
		switch (c) {
		case 'c':
			description = optarg;
			break;
		case 'd':
			defined = optarg;
			break;
		case 'e':
			developed = optarg;
			break;
		case 'g':
			gnu = optarg;
			break;
		case 'h':
			head = 1;
			break;
		case 'k':
			kernel = optarg;
			break;
		case 'o':
			operating = optarg;
			break;
		case 'p':
			os = optarg;
			break;
		case 'u':
			useful = optarg;
			break;
		case 'v':
			printf("%s v0.1.0\nCopyright (C) 2016 Alexei Frolov\n"
					"This program is distributed as free "
					"software under the\nterms of the GNU "
					"General Public License, version 3\n",
					PROG_NAME);
			return EXIT_SUCCESS;
		case 'H':
			usage(PROG_NAME, stdout);
			return EXIT_SUCCESS;
		default:
			usage(argv[0], stderr);
			return EXIT_FAILURE;
		}
	}
	if (optind != argc) {
		if (optind == argc - 1)
			linux = argv[optind];
		else {
			usage(argv[0], stderr);
			return EXIT_FAILURE;
		}
	}
	interject();
	putchar('\n');
	return EXIT_SUCCESS;
}

/* interject for a moment */
void interject()
{
	printf("I'd just like to interject for a moment. What you're ");
	printf("referring to as %s, is in fact, %s/%s, ", linux, gnu, linux);
	printf("or as I've recently taken to calling it, %s plus %s. ",
			gnu, linux);
	if (head)
		return;
	printf("%s is not a%s %s unto itself ", linux,
			isvowel(operating[0]) ? "n" : "", operating);
	printf("but rather another free component of a fully functioning "
			"%s system made useful by the %s ", gnu, useful);
	printf("comprising a full %s as defined by %s. ", os, defined);

	printf("Many computer users run a modified version of the %s system "
			"every day, without realizing it. ", gnu);
	printf("Through a peculiar turn of events, the version of %s which is "
			"widely used today is often called \"%s\"", gnu, linux);
	printf(", and many of its users are not aware that it is basically the "
			"%s system, developed by the %s. ", gnu, developed);

	printf("There really is a %s, and these people are using it, but it is "
			"just a part of the system they use. ", linux);
	printf("%s is the %s: %s. ", linux, kernel, description);
	printf("The %s is an essential part of a%s %s, ", kernel,
			isvowel(operating[0]) ? "n" : "", operating);
	printf("but useless by itself; it can only function within the "
			"context of a complete %s. ", operating);
	printf("%s is normally used in combination with the %s %s: the whole "
			"system is basically %s with %s added, or %s/%s", linux,
			gnu, operating, gnu, linux, gnu, linux);
	printf(". All these so-called \"%s\" distributions are really "
			"distributions of %s/%s.", linux, gnu, linux);
}

int isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void usage(char *s, FILE *f)
{
	fprintf(f, "usage: %s [OPTION]... [SYSTEM]\n", s);
	fprintf(f, "interject that SYSTEM is really GNU/SYSTEM\n\n");
	fprintf(f, "\t--description=DESC\n\t\tLinux is the kernel: DESC\n");
	fprintf(f, "\t--defined=DEF\n\t\tfully functioning OS as defined by DEF\n");
	fprintf(f, "\t--developed=DEV\n\t\tthe GNU system, developed by DEV\n");
	fprintf(f, "\t--gnu=GNU\n\t\tset the proper system prefix\n");
	fprintf(f, "\t-h, --head\n\t\tprint only the first sentence\n");
	fprintf(f, "\t-H, --help\n\t\tdisplay this help text and exit\n");
	fprintf(f, "\t--kernel=KERN\n\t\tLinux is the KERN\n");
	fprintf(f, "\t--operating=OPER\n\t\tLinux is not an OPER unto itself\n");
	fprintf(f, "\t--os=OS\n\t\ta complete OS as defined by\n");
	fprintf(f, "\t--useful=USE\n\t\tfully functioning GNU system made "
			"useful by the USE\n");
	fprintf(f, "\t-v, --version\n\t\tdisplay version information and exit\n");
}
