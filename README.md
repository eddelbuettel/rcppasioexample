## RcppAsioExample: Rcpp Example for Asio 

### About

This package provides a example for the [AsioHeaders](https://github.com/eddelbuettel/asioheaders)
package and its use from R via [Rcpp](https://www.rcpp.org).  It serves as an illustration of a
minimally viable package from which users derive their own extensions.

### Example

The following code snippet shows two commands. First, we load the package. Second, we run the
example from the help page of the `httpClient()`. In this example, `httpClient()` is called with
the arguments for the Apache.org site, and the top-level (ascii and short) file `robots.txt`. The
http client implemented here first shows all the relevant http headers, followed by the mere three
lines of content.

```r
R> library(RcppAsioExample)
R> example(httpClient)

httpClR> httpClient("www.apache.org", "/robots.txt")
Date: Sun, 12 Jul 2020 16:05:04 GMT
Server: Apache/2.4.18 (Ubuntu)
Last-Modified: Tue, 01 May 2018 08:13:23 GMT
ETag: "2f-56b208b432d55"
Accept-Ranges: bytes
Content-Length: 47
Cache-Control: max-age=3600
Expires: Sun, 12 Jul 2020 17:05:04 GMT
Connection: close
Content-Type: text/plain

User-agent: *
Disallow: /websrc
Crawl-Delay: 4
R>
```

### Author

Dirk Eddelbuettel

### License

GPL (>= 2)

