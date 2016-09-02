./corewarmaster -d 40 champions/test.cor >master
./corewar -dump 40 champions/test.cor >test
diff master test
