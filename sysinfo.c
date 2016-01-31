#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/sysctl.h>
#include <sys/param.h>
#include <sys/mount.h>

#define RESET_ALL       "\x1b[0m"
#define COLOR_RED       "\x1b[31m"
#define COLOR_GREEN     "\x1b[32m"
#define COLOR_YELLOW    "\x1b[33m"
#define COLOR_BLUE      "\x1b[34m"
#define COLOR_MAGENT    "\x1b[35m"
#define COLOR_CYAN      "\x1b[36m"
#ifdef COLOR16_SUPPORT
#   define COLOR_ORANGE "\x1b[33m"
#else
#   define COLOR_ORANGE "\x1b[38;5;9m"
#endif
#define TEXT_BOLD       "\x1b[1m"
#define TEXT_UNDERLINE  "\x1b[4m"

/* Printing */
char** get_extra_text(void);
char** get_ascii_apple(void);
void print_ascii_apple(void);

/* Information */
typedef char const* (*fpPrint)();
fpPrint* get_functions(void);
char const* get_user(void);
char const* get_hostname(void);
char const* get_osx_version(void);
char const* get_kernel_version(void);
char const* get_uptime(void);
char const* get_shell(void);
char const* get_terminal(void);
char const* get_cpu(void);
char const* get_gpu(void);
char const* get_ram(void);
char const* get_disk(void);

int main(int argc, char** argv)
{
    ((void)argc);
    ((void)argv);

    print_ascii_apple();
    return 0;
}

char**
get_extra_text(void)
{
    static char* text[30];
    text[0] = NULL;
    text[1] = NULL;
    text[2] = NULL;
    text[3] = NULL;
    text[4] = NULL;
    text[5] = NULL;
    text[6] = NULL;
    text[7] = NULL;
    text[8] = NULL;
    text[9] = NULL;
    text[10] = "User:";
    text[11] = "Hostname:";
    text[12] = "OS X Version:";
    text[13] = "Kernel Version:";
    text[14] = "Uptime:";
    text[15] = "Shell:";
    text[16] = "Terminal:";
    text[17] = "CPU:";
    text[18] = "GPU:";
    text[19] = "RAM:";
    text[20] = "Disk:";
    text[21] = NULL;
    text[22] = NULL;
    text[23] = NULL;
    text[24] = NULL;
    text[25] = NULL;
    text[26] = NULL;
    text[28] = NULL;
    text[28] = NULL;
    text[29] = NULL;
    return text;
}

char**
get_ascii_apple(void)
{
    static char* art[30];
    art[ 0] = COLOR_GREEN "                             ##"RESET_ALL;
    art[ 1] = COLOR_GREEN "                           #####"RESET_ALL;
    art[ 2] = COLOR_GREEN "                          #######"RESET_ALL;
    art[ 3] = COLOR_GREEN "                         ########"RESET_ALL;
    art[ 4] = COLOR_GREEN "                         ########"RESET_ALL;
    art[ 5] = COLOR_GREEN "                         #######"RESET_ALL;
    art[ 6] = COLOR_GREEN "                         ######"RESET_ALL;
    art[ 7] = COLOR_GREEN "            #######       ###      #######"RESET_ALL;
    art[ 8] = COLOR_GREEN "        ###############        ###############"RESET_ALL;
    art[ 9] = COLOR_GREEN "      ###########################################"RESET_ALL;
    art[10] = COLOR_GREEN "    ##########################################             "RESET_ALL;
    art[11] = COLOR_YELLOW"   #########################################               "RESET_ALL;
    art[12] = COLOR_YELLOW"  ########################################                 "RESET_ALL;
    art[13] = COLOR_YELLOW"  #######################################                  "RESET_ALL;
    art[14] = COLOR_YELLOW"  #######################################                  "RESET_ALL;
    art[15] = COLOR_ORANGE"  #######################################                  "RESET_ALL;
    art[16] = COLOR_ORANGE"  #######################################                  "RESET_ALL;
    art[17] = COLOR_ORANGE"  ########################################                 "RESET_ALL;
    art[18] = COLOR_ORANGE"  #########################################                "RESET_ALL;
    art[19] = COLOR_RED   "  ###########################################              "RESET_ALL;
    art[20] = COLOR_RED   "   ############################################            "RESET_ALL;
    art[21] = COLOR_RED   "   #############################################"RESET_ALL;
    art[22] = COLOR_RED   "    ############################################"RESET_ALL;
    art[23] = COLOR_MAGENT"     ##########################################"RESET_ALL;
    art[24] = COLOR_MAGENT"      ########################################"RESET_ALL;
    art[25] = COLOR_MAGENT"       ######################################"RESET_ALL;
    art[26] = COLOR_BLUE  "        ####################################"RESET_ALL;
    art[27] = COLOR_BLUE  "         #################################"RESET_ALL;
    art[28] = COLOR_BLUE  "           ##########          #########"RESET_ALL;
    art[29] = NULL;
    return art;
}

void
print_ascii_apple(void)
{
    fpPrint* functions;
    char** ascii;
    char** text;
    char const* str;

    functions = get_functions();
    ascii = get_ascii_apple();
    text = get_extra_text();
    while (*ascii != NULL)
    {
        if (*functions == NULL)
        {
            printf("%s\n", *ascii);
        }
        else
        {
            str = (*functions)();
            if (str != NULL)
                printf("%s " COLOR_CYAN "%s" RESET_ALL " %s\n", *ascii, *text, str);
            else printf("%s\n", *ascii);
        }

        functions = functions + 1;
        ascii = ascii + 1;
        text = text + 1;
    }
}

fpPrint*
get_functions(void)
{
    static fpPrint functions[30];
    functions[0] = NULL;
    functions[1] = NULL;
    functions[2] = NULL;
    functions[3] = NULL;
    functions[4] = NULL;
    functions[5] = NULL;
    functions[6] = NULL;
    functions[7] = NULL;
    functions[8] = NULL;
    functions[9] = NULL;
    functions[10] = get_user;
    functions[11] = get_hostname;
    functions[12] = get_osx_version;
    functions[13] = get_kernel_version;
    functions[14] = get_uptime;
    functions[15] = get_shell;
    functions[16] = get_terminal;
    functions[17] = get_cpu;
    functions[18] = get_gpu;
    functions[19] = get_ram;
    functions[20] = get_disk;
    functions[21] = NULL;
    functions[22] = NULL;
    functions[23] = NULL;
    functions[24] = NULL;
    functions[25] = NULL;
    functions[26] = NULL;
    functions[27] = NULL;
    functions[28] = NULL;
    functions[29] = NULL;

    return functions;
}

char const* get_user(void)
{
    return getlogin();
}

char const* get_hostname(void)
{
    static char ret[255];

    if (gethostname(ret, 255))
    {
        return NULL;
    }

    return ret;
}

char const* get_osx_version(void)
{
	FILE* fp;
	int versionlen;
	char version[64];
	size_t osversionlen;
	char osversion[64];
	static char ret[255];

	fp = popen("/usr/bin/sw_vers -productVersion", "r");
	if (!fp) return NULL;
	if (!fgets(version, sizeof(version) - 1, fp))
    {
        pclose(fp);
        return NULL;
    }
	pclose(fp);

    osversionlen = sizeof(osversion);
    if (sysctlbyname("kern.osversion", osversion, &osversionlen, NULL, 0))
        return NULL;

    versionlen = strlen(version);
    snprintf(ret, 255, "%.*s (%s)", versionlen - 1, version, osversion);
    return ret;
}

char const* get_kernel_version(void)
{
    static char ret[255];
    struct utsname sys;

    uname(&sys);
    if ((strlen(sys.sysname) + strlen(sys.version)) > 255)
        return NULL;

    snprintf(ret, 255, "%s %s", sys.sysname, sys.release);
    return ret;
}

char const* get_uptime(void)
{
    static char ret[255];
    struct timeval boottime;
    size_t len = sizeof(boottime);
    time_t diff;
    time_t days, hours, minutes;

    if (sysctlbyname("kern.boottime", &boottime, &len, NULL, 0))
        return NULL;

    diff = (time_t)difftime(time(NULL), boottime.tv_sec);
    days = diff / (60*60*24);
	hours = (diff / (60*60)) % 24;
	minutes = (diff / 60) % 60;

	snprintf(ret, 255, "%ld days, %ld hours and %ld minutes", days, hours, minutes);
    return ret;
}

char const* get_shell(void)
{
    static char ret[255];
    char* env;

    env = getenv("SHELL");
    memcpy(ret, env, strlen(env));
    return ret;
}

char const* get_terminal(void)
{
    static char ret[255];
    char* env;

    env = getenv("TERM");
    memcpy(ret, env, strlen(env));
    return ret;
}

char const* get_cpu(void)
{
    static char ret[255];
    size_t len = 255;

    if (sysctlbyname("machdep.cpu.brand_string", ret, &len, NULL, 0))
        return NULL;

    return ret;
}

/* Not used. Due to the fact it's taken quite long to load */
char const* get_gpu(void)
{
    static char ret[255];
    FILE* fp;
    char output[255];
    size_t i, len;
    char* cmd = "system_profiler -detailLevel mini SPDisplaysDataType 2> /dev/null | grep \"Chipset Model:\" | sed -e 's/Chipset Model://' | sed -e 's/^[ \\t ]*//'";

	fp = popen(cmd, "r");
	if (!fp) return NULL;
	if ((len = fread(output, 1, sizeof(output) - 1, fp)) == 0)
    {
        pclose(fp);
        return NULL;
    }
	pclose(fp);

    output[len] = '\0';

    len = strlen(output);
    memcpy(ret, output, len);
    for (i = 0; i < len; i++)
    {
        if (ret[i] == '\n')
        {
            ret[i] = ',';
        }
    }

    ret[len - 1] = '\0';
    return ret;
}

char const* get_ram(void)
{
    static char ret[255];
    int64_t mem;
    size_t len = 255;

    if (sysctlbyname("hw.memsize", &mem, &len, NULL, 0))
        return NULL;

    mem = mem / 1024 / 1024 / 1024;

    snprintf(ret, 255, "%lld GiB", mem);
    return ret;
}

char const* get_disk(void)
{
    static char ret[255];
    struct statfs fs;
    double free, all;

	statfs("/", &fs);

	free = (fs.f_bsize * fs.f_bfree) / 1000 / 1000 / 1000;
	all = (fs.f_bsize * fs.f_blocks) / 1000 / 1000 / 1000;

	snprintf(ret, 255, "%.f GB / %.f GB", free, all);
    return ret;
}

