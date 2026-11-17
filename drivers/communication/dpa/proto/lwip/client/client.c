

static int request_func_stub(void *param, int len)
{
    return 0;
}
typedef int (*REQUEST_FUNC)(void *, int);
REQUEST_FUNC g_request_func = request_func_stub;

void client_init(int (*func)(void *, int))
{
    g_request_func = func;
};

int client_send(void *param, int len)
{
    return g_request_func(param, len);
}