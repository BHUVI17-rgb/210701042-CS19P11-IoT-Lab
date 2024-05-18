import urllib.request
import urllib.parse
uname = 'bhuvaneswaran@rajalakshmi.edu.in'
hashCode = '9890db2b86d4bf292adfc44fe0e19fc417e6f6a7'
sender = 'TXTLCL'
numbers = ('919791519152','919994940914')
message = 'Test message sent from my Raspberry Pi'
def sendSMS(uname, hashCode, numbers, sender, message):
    data = urllib.parse.urlencode({'username': uname, 'hash': hashCode,
    'numbers': numbers, 'message' : message, 'sender': sender})
    data = data.encode('utf-8')
    request = urllib.request.Request("http://api.textlocal.in/send/?")
    f = urllib.request.urlopen(request, data)
    fr = f.read()
    return(fr)
resp = sendSMS(uname, hashCode, numbers, sender, message)
print (resp)