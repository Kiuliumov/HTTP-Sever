#ifndef REQUEST_H
#define REQUEST_H

#define MAX_METHOD_LEN 8
#define MAX_PATH_LEN 256
#define MAX_VERSION_LEN 16

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
