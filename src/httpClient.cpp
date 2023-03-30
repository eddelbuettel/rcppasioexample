
// cf https://think-async.com/Asio/asio-1.16.1/src/examples/cpp03/iostreams/http_client.cpp

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <asio/ip/tcp.hpp>

#include <Rcpp.h>

//' Example Asio application
//'
//' This function implements a very simple http client. It follows the \code{http_client.cpp}
//' example in the Asio documentation but has been adapted to be used as an example function
//' here.
//' @param host A character variable with an internet host name
//' @param path A character variable with an accessible path
//' @return Nothing is returned as the function is invoked for its a side-effect of display
//' what is retrieved.
//' @examples
//' \dontrun{
//' ## now commented-out / inactive as the redirect upsets R's own checking
//' httpClient("www.apache.org", "/robots.txt")
//' }
// [[Rcpp::export]]
void httpClient(const std::string & host, const std::string & path) {

    asio::ip::tcp::iostream s;

    // The entire sequence of I/O operations must complete within 60 seconds.
    // If an expiry occurs, the socket is automatically closed and the stream
    // becomes bad.
    s.expires_after(asio::chrono::seconds(60));

    // Establish a connection to the server.
    s.connect(host.c_str(), "http");
    if (!s) Rcpp::stop("Unable to connect: %s", s.error().message());

    // Send the request. We specify the "Connection: close" header so that the
    // server will close the socket after transmitting the response. This will
    // allow us to treat all data up until the EOF as the content.
    s << "GET " << path << " HTTP/1.0\r\n";
    s << "Host: " << host << "\r\n";
    s << "Accept: */*\r\n";
    s << "Connection: close\r\n\r\n";

    // By default, the stream is tied with itself. This means that the stream
    // automatically flush the buffered output before attempting a read. It is
    // not necessary not explicitly flush the stream at this point.

    // Check that response is OK.
    std::string http_version;
    s >> http_version;
    unsigned int status_code;
    s >> status_code;
    std::string status_message;
    std::getline(s, status_message);
    if (!s || http_version.substr(0, 5) != "HTTP/") Rcpp::stop("Invalid response\n");
    if (status_code != 200) Rcpp::stop("Response returned with status code %u\n", status_code);;

    // Process the response headers, which are terminated by a blank line.
    std::string header;
    while (std::getline(s, header) && header != "\r")
        Rcpp::Rcout << header << "\n";
    Rcpp::Rcout << "\n";

    // Write the remaining data to output.
    Rcpp::Rcout << s.rdbuf();

}
