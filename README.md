Grove Accelerometer ADXL 356
==============


## Note：
The annalog output of sensor is 0~1.8V,and the accuracy of the sensor is 5% of the full scale range.
But the ADC resolution of arduino UNO(or other board based on atmega 328) is 10 bit.and the power supply is 5V,So it will cause deviation when using adrino for adc conversion.  
If using other board which has the lower power voltage,or the higher adc resolution,the deviation value will be decresed.



***
This software is written by downey  for seeed studio<br>
Email:dao.huang@seeed.cc
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
