#include <iostream>
#include <string>

#include "json/json.h"

#include "foo/foo.h"
#include "libfoo/libfoo.h"

using namespace std;

int main(int argc, char* argv[]){
    cout << "hello world!" << endl;

    cout << "hello " << get_name("matthew") << endl;

    cout << "hello " << get_version() << endl;

    string json_str = "{\"name\":\"json\"}";
    Json::Reader reader;
    Json::Value json;
    reader.parse(json_str, json);
    cout << "hello " << json["name"].asString()<< endl;
    return 0;
}

