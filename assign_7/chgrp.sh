chown :group1 f1.txt

chown Akshay:group1 cron.sh

chown --from=:group1 group2 cron.sh

chown --references=f1.txt bctest.sh

chgrp group1 f1.txt

chgrp -R group1 example

chgrp -c group1 f2.txt

chgrp -f group2 f2.txt

chgrp -v group3 f2.txt