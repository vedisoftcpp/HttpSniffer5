#ifndef URL_EJECTOR_TEST_H
#define URL_EJECTOR_TEST_H

#include <gtest/gtest.h>
#include "../urlejector.h"

using namespace HttpSniffer;

TEST(UrlEjectorTest, simple_header)
{
    string header = "Host: google.com\r\n";

    UrlEjector ejector;
    ejector.eject(header);

    vector<string> result;
    result.push_back("google.com");

    EXPECT_EQ(result, ejector.urls);
    EXPECT_EQ(header, "\r\n");
}

TEST(UrlEjectorTest, several_headers)
{
    string header = "noise Host: google.com\r\n noise Host: yandex.ru\r\n";

    UrlEjector ejector;
    ejector.eject(header);

    vector<string> result;
    result.push_back("google.com");
    result.push_back("yandex.ru");

    EXPECT_EQ(result, ejector.urls);
}

#endif // URL_EJECTOR_TEST_H
