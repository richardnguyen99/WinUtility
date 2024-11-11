#include "pch.h"

void
showHelpMessage(int exitCode);

int
_tmain(int argc, _TCHAR *argv[])
{
    static int verbose_flag, help_flag;
    int c;

    for (;;)
    {
        static struct option long_options[] = {
            {_T("verbose"), ARG_NONE, &verbose_flag, 1       },
            {_T("help"),    ARG_NONE, 0,             _T('h') },
            {ARG_NULL,      ARG_NULL, ARG_NULL,      ARG_NULL}
        };

        int option_index = 0;
        c = getopt_long(argc, argv, _T("h"), long_options, &option_index);

        // Check for end of operation or error
        if (c == -1)
            break;

        // Handle options
        switch (c)
        {
        case '?':
        case _T('h'):
            showHelpMessage(EXIT_SUCCESS);

        default:
            showHelpMessage(EXIT_FAILURE);
        }
    }

    if (verbose_flag)
        _tprintf(_T("verbose flag is set\n"));

    if (optind < argc)
    {
        _tprintf(_T("non-option ARGV-elements: "));

        while (optind < argc)
            _tprintf(_T("%s "), argv[optind++]);

        _tprintf(_T("\n"));
    }

    return 0;
}

void
showHelpMessage(int exitCode)
{
    _tprintf(_T("Usage: WinCat [OPTIONS] [...FILES]\n"));
    exit(exitCode);
}