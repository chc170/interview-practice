# Analyse words
# Written in Python
# Author: Chih-Chuan Chan
# Date: 4/8/2013
# Example:
#   analyse_words.py www.yahoo.com
#   analyse_words.py www.yahoo.com all
# Page redirection will not be executed

import httplib, urllib, sys, re, operator

def fetch_web_page(url):
    ''' (string) -> string
    Return the web content from the url link.
    '''

    # analyse URL
    try:
        pos = url.index("/")
        host = url[:pos]
        url = url[pos:]
    except ValueError:
        host = url
        url = ""
    
    # construct http request
    headers = {
        "Content-Type" : "application/x-www-form-urlencoded"
    }
    conn = httplib.HTTPConnection(host)

    # send request
    conn.request("GET", url, "", headers)

    # get response
    response = conn.getresponse()

    if response.status == 200:
        data = response.read()
        conn.close()
        return True, data
    else:
        conn.close()
        return False, ""

def analyse_words(raw_data):
    ''' (string) -> list
    Return a key-value list which keys are words, values are frequencies.
    '''

    # get body
    start = raw_data.index("<body")
    end = raw_data.index("</body>")
    body = raw_data[start:end]
    
    # remove tags, new line, extra spaces
    data = re.sub('<[^<]+>', '', body)
    data = re.sub('\n+', ' ', data)
    data = re.sub('[ ]+', ' ', data)
    
    # separate into words
    words = data.split(' ')

    # loop through all words and count the number for each
    word_dict = {}

    for word in words:
        if word not in word_dict.keys():
            word_dict[word] = 1
        else:
            word_dict[word] += 1

    return word_dict

# Main function
if __name__ == '__main__':
    # fetch system argument
    url = sys.argv[1]
    if len(sys.argv) > 2 and sys.argv[2] == 'all':
        stop = False
    else:
        stop = True

    # fetch web content
    status, data = fetch_web_page(url)

    if status == False:
        print "Unable to fetch content from the URL."
        exit(0)

    # analyse web page
    result = analyse_words(data)

    # sort by frequency
    sorted_result = sorted(result, key=result.get)
    sorted_result.reverse()
    
    # print result
    count = 0
    for key in sorted_result:
        print key, ': ', result[key]
        if count % 50 == 49 and stop:
            raw_input('More...')
        count += 1
        
    
    

