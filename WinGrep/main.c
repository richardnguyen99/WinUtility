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
            {_T("brief"),   ARG_NONE, &verbose_flag, 0       },
            {_T("help"),    ARG_NONE, 0,             _T('h') },
            {_T("add"),     ARG_NONE, 0,             _T('a') },
            {_T("append"),  ARG_NONE, 0,             _T('b') },
            {_T("delete"),  ARG_REQ,  0,             _T('d') },
            {_T("create"),  ARG_REQ,  0,             _T('c') },
            {_T("file"),    ARG_REQ,  0,             _T('f') },
            {ARG_NULL,      ARG_NULL, ARG_NULL,      ARG_NULL}
        };

        int option_index = 0;
        c                = getopt_long(
            argc, argv, _T("habc:d:f:"), long_options, &option_index
        );

        // Check for end of operation or error
        if (c == -1)
            break;

        // Handle options
        switch (c)
        {
        case 0:
            /* If this option set a flag, do nothing else now. */
            if (long_options[option_index].flag != 0)
                break;

            _tprintf(_T("option %s"), long_options[option_index].name);

            if (optarg)
                _tprintf(_T(" with arg %s"), optarg);

            _tprintf(_T("\n"));

            break;

        case _T('a'):
            _tprintf(_T("option -a\n"));
            break;

        case _T('b'):
            _tprintf(_T("option -b\n"));
            break;

        case _T('c'):
            _tprintf(_T("option -c with value `%s'\n"), optarg);
            break;

        case _T('d'):
            _tprintf(_T("option -d with value `%s'\n"), optarg);
            break;

        case _T('f'):
            _tprintf(_T("option -f with value `%s'\n"), optarg);
            break;

        case '?':
        case _T('h'):
        default:
            showHelpMessage(EXIT_SUCCESS);
        }
    }

    if (verbose_flag)
        _tprintf(_T("verbose flag is set\n"));

    if (optind < argc)
    {
        _tprintf(_T("non-option ARGV-elements: "));

        while (optind < argc)
            _tprintf(_T("%ls"), argv[optind++]);

        _tprintf(_T("\n"));
    }
    return 0;
}

void
showHelpMessage(int exitCode)
{
    _tprintf(_T("Usage: wingrep [OPTIONS] [...FILES]\n"));
    exit(exitCode);
}