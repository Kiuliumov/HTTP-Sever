#include <stdio.h>
#include <string.h>
#include "request.h"

#include <string.h>
#include "request.h"


HttpMethod parse_method(const char *method_str)
{
    if (strcmp(method_str, "GET") == 0)
        return HTTP_GET;
    if (strcmp(method_str, "POST") == 0)
        return HTTP_POST;
    if (strcmp(method_str, "DELETE") == 0)
        return HTTP_DELETE;
    if (strcmp(method_str, "PUT") == 0)
        return HTTP_PUT;
    if (strcmp(method_str, "HEAD") == 0)
        return HTTP_HEAD;
    if (strcmp(method_str, "OPTIONS") == 0)
        return HTTP_OPTIONS;
    if (strcmp(method_str, "PATCH") == 0)
        return HTTP_PATCH;
    if (strcmp(method_str, "CONNECT") == 0)
        return HTTP_CONNECT;
    if (strcmp(method_str, "TRACE") == 0)
        return HTTP_TRACE;
    return HTTP_UNKNOWN;
}

const char *method_to_string(HttpMethod method)
{
    switch (method)
    {
    case HTTP_GET:
        return "GET";
    case HTTP_POST:
        return "POST";
    case HTTP_DELETE:
        return "DELETE";
    case HTTP_PUT:
        return "PUT";
    case HTTP_HEAD:
        return "HEAD";
    case HTTP_OPTIONS:
        return "OPTIONS";
    case HTTP_PATCH:
        return "PATCH";
    case HTTP_CONNECT:
        return "CONNECT";
    case HTTP_TRACE:
        return "TRACE";
    default:
        return "UNKNOWN";
    }
}

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
