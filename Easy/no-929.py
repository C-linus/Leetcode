class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_email_addresses = set()

        for email in emails:
            local_name , domain_name = email.split('@')
            local_name = local_name.split('+')[0]
            local_name = local_name.replace('.','')
            unique_email_addresses.add(local_name + '@' + domain_name)

        return unique_email_addresses.__len__()
