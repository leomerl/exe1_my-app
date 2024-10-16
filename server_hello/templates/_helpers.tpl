{{- define "server_hello.name" -}}
{{- .Chart.Name | trunc 63 | trimSuffix "-" -}}
{{- end }}

{{- define "server_hello.fullname" -}}
{{- printf "%s-%s" .Release.Name (include "server_hello.name" .) | trunc 63 | trimSuffix "-" -}}
{{- end }}

{{- define "server_hello.labels" -}}
app.kubernetes.io/name: {{ include "server_hello.name" . }}
app.kubernetes.io/instance: {{ .Release.Name }}
app.kubernetes.io/version: {{ .Chart.AppVersion }}
app.kubernetes.io/managed-by: {{ .Release.Service }}
{{- end }}
