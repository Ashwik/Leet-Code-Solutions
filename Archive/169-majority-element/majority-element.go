func majorityElement(nums []int) int {
    
    count:=1
    num:= nums[0]

    for i:=1;i<len(nums);i++ {
        if nums[i] == num {
            count++
        }else if count==0 {
            count++
            num = nums[i]
        }else {
            count--
        }
    }
    return num
}