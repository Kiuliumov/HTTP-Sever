#ifndef ROUTER_H
#define ROUTER_H

#include "request.h"

#define MAX_ROUTES 32

typedef void (*RouteHandler)(int client_fd, HttpRequest *req);

typedef struct
{
    HttpMethod method;
    const char *path;
    RouteHandler handler;
} Route;

void add_route(HttpMethod method, const char *path, RouteHandler handler);

void handle_request(int client_fd, HttpRequest *req);

#endif
