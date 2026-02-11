#ifndef REQUEST_H
#define REQUEST_H

#define MAX_METHOD_LEN 8
#define MAX_PATH_LEN 256
#define MAX_VERSION_LEN 16

// HTTP methods
#define GET_METHOD "GET";
#define POST_METHOD "POST";
#define DELETE_METHOD "DELETE";
#define PUT_METHOD "PUT";
#define HEAD_METHOD "HEAD";
#define OPTIONS_METHOD "OPTIONS";
#define PATCH_METHOD "PATCH";
#define CONNECT_METHOD "CONNECT";
#define TRACE_METHOD "TRACE";



typedef struct
{
    char method[MAX_METHOD_LEN];
    char path[MAX_PATH_LEN];
    char version[MAX_VERSION_LEN];
} HttpRequest;

/**
 * Parses the HTTP request line.
 * Example:
 *   GET /index.html HTTP/1.1
 *
 * Returns 0 on success, -1 on failure.
 */

int parse_http_request(const char *buffer, HttpRequest *req);

#endif
