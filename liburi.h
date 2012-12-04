/*
 * Copyright 2012 Mo McRoberts.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef LIBURI_H_
# define LIBURI_H_                      1

# include <sys/types.h>

typedef struct uri_struct URI;

# if (!defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L) && !defined(restrict)
#  define restrict
# endif

# if defined(__cplusplus)
extern "C" {
# endif

	/* Create a URI from a string and optional base URI */
	URI *uri_create_str(const char *restrict uristr, const URI *restrict uri);
	
	/* Create a URI from an existing URI and optional base URI */
	URI *uri_create_uri(URI *restrict source, const URI *restrict base);

	/* Destroy a URI, freeing the resources it uses */
	int uri_destroy(URI *uri);

	/* Return 1 if the URI specified is absolute, 0 if it is relative */
	int uri_absolute(URI *uri);
	
	/* Copy the URI's scheme into the buffer provided */
	size_t uri_scheme(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's authentication information into the buffer provided */
	size_t uri_auth(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's hostname into the buffer provided */
	size_t uri_host(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's port into the buffer provided */
	size_t uri_port(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's path into the buffer provided */
	size_t uri_path(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's query string into the buffer provided */
	size_t uri_query(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Copy the URI's fragment into the buffer provided */
	size_t uri_fragment(URI *restrict uri, char *restrict buf, size_t buflen);

	/* Return the URI's port number, if present, as an integer */
	int uri_portnum(URI *uri);

	/* Copy the whole URI, as a string, into the buffer provided */
	size_t uri_str(URI *restrict uri, char *restrict buf, size_t buflen);

# if defined(__cplusplus)
}
# endif

#endif /*!LIBURI_H_*/
