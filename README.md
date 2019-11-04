
1) RAID 0  (Striped array with no fault tolerance)
    
    gcc raid0.c


2) RAID 1  (Disk mirroring)
    
    gcc raid1.c
      

3) RAID 5 (Striping with parity i.e. Striped array with independent disks and distributed parity) 
    
    gcc raid5.c


4) RAID 3 (Parallel access array with dedicated parity disk) 
    
    gcc raid3.c


 5) RAID 4 (Striped array with independent disks and a dedicated parity disk)
    
    gcc raid4.c
