#ifndef REQUEST_H
#define REQUEST_H

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_PATH_LEN 256
#define MAX_VERSION_LEN 16

    typedef enum
    {
        HTTP_GET,
        HTTP_POST,
        HTTP_DELETE,
        HTTP_PUT,
        HTTP_HEAD,
        HTTP_OPTIONS,
        HTTP_PATCH,
        HTTP_CONNECT,
        HTTP_TRACE,
        HTTP_UNKNOWN
    } HttpMethod;

    typedef struct
    {
        HttpMethod method;
        char path[MAX_PATH_LEN];
        char version[MAX_VERSION_LEN];
    } HttpRequest;

    HttpMethod parse_method(const char *method_str);

    const char *method_to_string(HttpMethod method);
    int parse_http_request(const char *buffer, HttpRequest *req);

#ifdef __cplusplus
}
#endif

#endif
