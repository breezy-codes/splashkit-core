//
//  test_bundles.cpp
//  splashkit
//
//  Created by Andrew Cain on 29/08/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#include "twitter.h"
#include "utils.h"
#include <iostream>
#include "json.h"
#include "web.h"
using namespace std;
using namespace splashkit_lib;

void run_twitter_test()
{
    json twitter_post = create_json();
    
    // Keep these secret
    json_set_string(twitter_post, "oauth_consumer_key", "VlU5u3eZD8O9FLLjCJ7X7SZCm");
    json_set_string(twitter_post, "oauth_consumer_secret", "JdmKx1uYTFB5RL3Whbg6pyppQXGKt2NrHtmWQgWID37fWDaadb");
    json_set_string(twitter_post, "oauth_token", "777822290318757888-ZTefOHbqKd1huzc7cf5BLDZwfT36rgG");
    json_set_string(twitter_post, "oauth_token_secret", "gHT5YN7biHTVhOpK4AT4tsxZRVODDNL92iiAT8igE2FUf");
    
    json_set_string(twitter_post, "status", "#omg I'm so full! #killerkebabs #abrakebabra");
    
    new_tweet(twitter_post);
}
