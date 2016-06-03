#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

static char *PROG_NAME = "interject";

static char *linux = "Linux";
static char *gnu = "GNU";
static char *operating = "operating system";
static char *useful = "GNU corelibs, shell utilities and vital system components";
static char *os = "OS";
static char *defined = "POSIX";

static int head = 0;

static char* usage;

void interject();
int isvowel(char c);

int main(int argc, char **argv)
{
	int c;
	static struct option long_opts[] = {
		{ "defined", required_argument, 0, 'd' },
		{ "gnu", required_argument, 0, 'g' },
		{ "head", no_argument, 0, 'h' },
		{ "help", no_argument, 0, 'z' },
		{ "operating", required_argument, 0, 'o' },
		{ "os", required_argument, 0, 'p' },
		{ "useful", required_argument, 0, 'u' },
		{ "version", no_argument, 0, 'v' },
		{ 0, 0, 0, 0 }
	};
	while ((c = getopt_long(argc, argv, "g:h", long_opts, NULL)) != EOF) {
		switch (c) {
		case 'd':
			defined = optarg;
			break;
		case 'g':
			gnu = optarg;
			break;
		case 'h':
			head = 1;
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
			printf("%s v0.1.0\n", PROG_NAME);
			return EXIT_SUCCESS;
		case 'z':
			break;
		default:
			break;
		}
	}
	if (optind != argc) {
		if (optind == argc - 1)
			linux = argv[optind];
		else {
			fprintf(stderr, "%s\n", "usage:");
			return EXIT_FAILURE;
		}
	}
	interject();
	putchar('\n');
	return EXIT_SUCCESS;
}

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
			"%s system, made useful by the %s ", gnu, useful);
	printf("comprising a full %s as defined by %s.", os, defined);
}

int isvowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
