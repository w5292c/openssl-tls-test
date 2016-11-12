#include <stdio.h>
#include <assert.h>
#include <openssl/ssl.h>

int main(int argc, char **argv)
{
  SSL_library_init();
  SSL_CTX *const sslContext = SSL_CTX_new(TLSv1_2_client_method());
  assert(sslContext);
  SSL *const ssl = SSL_new(sslContext);
  assert(ssl);

done:
  SSL_free(ssl);
  SSL_CTX_free(sslContext);
  return 0;
}
