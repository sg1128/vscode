# Created by J. Yun, SCH Univ., yun@sch.ac.kr

import requests

url = 'http://203.253.128.161:7579/Mobius/sch20181498_/dust/la'
headers = {'Accept':'application/json',
			'X-M2M-RI':'12345',
			'X-M2M-Origin':'SOrigin'}

r = requests.get(url, headers=headers)

try:
	r.raise_for_status()
	jr = r.json()
	
	print(jr)
	print(jr['m2m:cin']['con'])
except Exception as exc:
	print('There was a problem: %s' % (exc))
