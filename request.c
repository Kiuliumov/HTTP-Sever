#include <stdio.h>
#include <string.h>
#include "request.h"

int parse_http_request(const char *buffer, HttpRequest *req)
{
    if (!buffer || !req)
        return -1;

    if (sscanf(buffer, "%7s %255s %15s",
               req->method,
               req->path,
               req->version) != 3)
    {
        return -1;
    }

    return 0;
}
